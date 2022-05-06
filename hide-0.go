package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os"
)

const (
	S = 54 // standard size of bmp headers
	T = 32 // number of bytes needed to hide the text length
	C = 4  // number of bytes needed to hide a character
)

// modify hides an integer to a byte slice
// 在上面我们讲过，小端刚好和大端相反的，所以在转成小端模式的时候，只要将[]byte数组的下标首尾对换一下位置就可以了
func f3() {
    var v3 uint32
    var b3 [4]byte
    v3 = 257
    // 将 256转成二进制就是
    // | 00000000 | 00000000 | 00000001 | 00000001 |
    // | b3[0]    | b3[1]   | b3[2]    | [3]      | // 这里表示b3数组每个下标里面存放的值
 
    // 这里直接使用将uint32l强转成uint8
    // | 00000000 0000000 00000001 | 00000001  直接转成uint8后等于 1
    // |---这部分go在强转的时候扔掉---|
    b3[0] = uint8(v3)
 
    // | 00000000 | 00000000 | 00000001 | 00000001 | 右移8位 转成uint8后等于 1
    // 下面是右移后的数据
    // |          | 00000000 | 00000000 | 00000001 |
    b3[1] = uint8(v3 >> 8)
 
    // | 00000000 | 00000000 | 00000001 | 00000001 | 右移16位 转成uint8后等于 0
    // 下面是右移后的数据
    // |          |          | 00000000 | 00000000 |
    b3[2] = uint8(v3 >> 16)
 
    // | 00000000 | 00000000 | 00000001 | 00000001 | 右移24位 转成uint8后等于 0
    // 下面是右移后的数据
    // |          |          |          | 00000000 |
    b3[3] = uint8(v3 >> 24)
 
    fmt.Printf("%+v\n", b3)
    // 所以最终将uint32转成[]byte数组输出为
    // [1 1 0 0 ]
}
func modify(value int, pix []byte, size int) {
	for i := 0; i < size; i++ {
		pix[i]=( pix[i] & 254 )
		var c byte=uint8(value)
	    var d byte=c & 3
		pix[i]=pix[i] | d
		value=value>>2
		// TODO: write your code here
		// replace last 2 bits of pix[i] with the last 2 bits of value
		// the next iteration repeats with the next 2 bits of value
	}
}

var (
	srcImage  string // input image name
	srcTxt    string // input text name
	destImage string // output doctored image name
)

// init sets command line arguments
func init() {
	// DON'T modify this function!!!
	flag.StringVar(&srcImage, "i", "", "input image name")
	flag.StringVar(&srcTxt, "t", "", "input text name")
	flag.StringVar(&destImage, "d", "", "output doctored image name")
}

func main() {
	// parse command line arguments
	flag.Parse()
	if srcImage == "" || srcTxt == "" || destImage == "" {
		flag.PrintDefaults()
		os.Exit(1)
	}
	// read input image to a byte slice p
	p, err := ioutil.ReadFile(srcImage)
	if err != nil {
		fmt.Printf("Read image file failed, err = %v\n", err)
		os.Exit(1)
	}
	// read input text to a byte slice t
	t, err := ioutil.ReadFile(srcTxt)
	if err != nil {
		fmt.Printf("Read text file failed, err = %v\n", err)
		os.Exit(1)
	}
	// check if the text is too big
	if T+len(t)*C > len(p[S:]) {
		fmt.Println("The text file is too big")
		os.Exit(1)
	}
	// save the text length to p
	modify(len(t), p[S:S+T], T)
	// save the content of text to p
	for i := 0; i < len(t); i++ {
		offset := S + T + C*i
		modify(int(t[i]), p[offset:offset+C], C)
	}
	// write the modified p to destImage
	err = ioutil.WriteFile(destImage, p, 0666)
	if err != nil {
		fmt.Printf("Write doctored image failed, err = %v\n", err)
		os.Exit(1)
	}
}
