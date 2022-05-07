package main

import (
	"flag"
	"os"
	"fmt"
	"io/ioutil"
)
var length int

const (
	S = 54 // standard size of header
	T = 32 // number of bytes needed to hide the text length
	C = 4  // number of bytes needed to hide a character
)

var (
	image string // input doctor image name
	txt   string // output text name
)

// init sets command line arguments
func init() {
	// DON'T modify this function!!!
	flag.StringVar(&image, "i", "", "input image name")
	flag.StringVar(&txt, "t", "", "output text name")
}
func duqulength(pix[] byte,size int){
	var a byte
	for i:=0;i<size;i++{
		a=a|(pix[i] & 3)
		a=a<<2
	}
}
func duqu(t byte,pix[] byte,size int){
	for i:=0;i<size;i++{
		t=t| (pix[i]&3)
		t=t<<2
	}
}


func main() {
	// parse command line arguments
	flag.Parse()
	if image == "" || txt == "" {
		flag.PrintDefaults()
		os.Exit(1)
	}
		p, err := ioutil.ReadFile(image)
	if err != nil {
		fmt.Printf("Read image file failed, err = %v\n", err)
		os.Exit(1)
	}
	// read input text to a byte slice t
	t, err := ioutil.ReadFile(txt)
	duqulength(p[S:S+T] ,T)
	for i:=0;i<length;i++{
		offset:=S+T+C*i
		duqu(t[i],p[offset:offset+C],C)
	}
	err = ioutil.WriteFile(txt, t, 0666)
	if err != nil {
		fmt.Printf("Write doctored image failed, err = %v\n", err)
		os.Exit(1)
	}
	// TODO: write your code here
}