#!/bin/bash
sudo apt update && sudo apt upgrade
sudo apt install nano vim python-is-python3 python3-venv python3-pip
python -m venv .my_venv
source .my_venv/bin/activate 
python -m pip install flask

cat <<EOF > hello.py
from flask import Flask

app = Flask(__name__)

@app.route('/')
def say_hello():
	return '<p>Hello, World, I am a Flask app!</p>'

@app.route('/about')
def about():
	return '<a href="https://flask.palletsprojects.com/en/stable/">Flask Documentation</a>\n' \
	'<p>This is a simple application running on flask.</p>'
EOF

flask --app hello run --host=0.0.0.0
