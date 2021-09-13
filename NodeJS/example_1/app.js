const express = require('express')
const routes  = require('./routes')
const http = require('http')
const path = require('path')
const urlencoded = require('url')
const bodyParser = require('body-parser')
const json = require('json')
const logger = require('logger')
const methodOverride = require('method-override')

const nano = require('nano')('http://localhost:5948')

const db = nano.use('address')

var app = express;

app.set('port', process.env.PORT || 300);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', pug)

app.use(bodyParser.json());
app.use(bodyParser.urlencoded());
app.use(methodOverride());
app.use(express.static(path.join(__dirname, 'public')));

app.get('/', routes.index);

app.post('/createdb', function (req, res) {
    nano.db.create(req.body.dbname, function (err) {
        if(err) {
            res.send("Error creating Database" + req.body.dbname);
            return;
        }

        req.send("Database : " + req.body.dbname + " created successfully")
    });
});

app.post('/new_contact', function(req,res) {
    var name = req.body.name;
    var phone = req.body.phone;

    db.insert({name:name, phone:phone, crazy:true}, phone, function(err,body, header){
        if(err) {
            res.send("Error creating contact");
            return;
        }

        rs.send("Contact created successfully..");
    });
});

app.post('/view_contact', function (req, res) {
    var alldoc = "Allowing are the contacts";
    db.get(req.body.phone, {revs_info:true}, function(err, body) {
        if(!err) {
            console.log(body);
        }
        if(body) {
            alldoc += " Name: "+body.name+"<br>Phone Number: "+body.phone;
        }
        else {
            alldoc = "No records found";
        }
        res.send(alldoc);
    });
});

app.post('/delete_contact' , function(req , res){
    db.get(req.body.phone, {revs_info: true}, function(err, body){
        if(!err) {
            db.destroy(req.body.phone, body._rev, function(err, body) {
                if(err) {
                    res.send("Error deleting Contact");
                }
                res.send("Contact deleted successfully");
            });
        }
    })
   res.send('hello from delete_contact server :)');

});


http.createServer(app).listen(app.get('port'), function() {
    console.log("Express server listening on port " + app.get('port'));
});