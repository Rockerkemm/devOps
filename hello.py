from flask import Flask

app = Flask(__name__)

@app.route('/')
def say_hello():
	return '<p>Hello, World, I am a Flask app!</p>'

@app.route('/about')
def about():
	return '<a href="https://flask.palletsprojects.com/en/stable/">Flask Documentation</a>\n' 	'<p>This is a simple application running on flask.</p>'
