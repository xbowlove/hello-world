package main

import (
	"flag"
	"os"
)

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

func main() {
	// parse command line arguments
	flag.Parse()
	if image == "" || txt == "" {
		flag.PrintDefaults()
		os.Exit(1)
	}
	// TODO: write your code here
}
