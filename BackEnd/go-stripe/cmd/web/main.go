// This will be the front-end of the web-app

package main

import (
	"html/template"
	"log"
	"strconv"
)

const version="1.0.0"
const cssVersion="1"

type config struct {
	port int
	env string
	api string
	db struct {
		dsn string
	}
	stripe struct {
		secret_key string
		public_key string
	}
}

type application struct {
	config config
	infoLog *log.Logger
	errorLog *log.Logger
	templateCache map[string]*template.Template
	version string
}

func main() {
	var i int = 42
	var j string
	j = strconv.Itoa(i)
	println(j)
}