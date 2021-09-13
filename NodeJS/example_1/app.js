var express = require('express')
var routes  = require('./routes')
var http = require('http')
var path = require('path')
var urlencoded = require('url')
var bodyParser = require('body-parser')
var json = require('json')
var logger = require('logger')
var methodoverride = require('method-override')

var nano = require('nano')('http://localhost:5948')

var db = nano.use('address')

var app = express

