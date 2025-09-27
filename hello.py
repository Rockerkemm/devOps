from flask import Flask

app = Flask(__name__)

@app.route('/')
def say_hello():
	return '<p>This is another string!</p> \n<p>Welcome, World, I am a Flask app!</p>'

@app.route('/about')
def about():
	return '<a href="https://flask.palletsprojects.com/en/stable/">Flask Documentation</a>\n' 	'<p>This is a simple application running on flask.</p>'
		   '<a href="https://www.python.org">Python Web</a>'

@app.route('/about')
def about():
	return '<a href="C23387203@mytudublin.ie">C23387203@mytudublin.ie</a>\n' 	'<p>Student Email</p>'
