from flask import Flask
import redis
import json
import time

app = Flask(__name__)

# Connect to Redis server
r = redis.Redis(host='redis-server', port=6379, decode_responses=True)

@app.route('/')
def say_hello():
    data = r.get('home')
    if data is not None:
        data = json.loads(data)
        # 600 seconds == 10 minutes
        if time.time() - data['time'] <= 600:
            return data['html']
    
    html_content = '<p>This is another string!</p> \n<p>Welcome, World, I am a Flask app!</p>'
    r.set('home', json.dumps({
        'html': html_content,
        'time': time.time()
    }))
    return html_content

@app.route('/about')
def about():
    data = r.get('about')
    if data is not None:
        data = json.loads(data)
        # 600 seconds == 10 minutes
        if time.time() - data['time'] <= 600:
            return data['html']
    
    html_content = '<a href="https://flask.palletsprojects.com/en/stable/">Flask Documentation</a>\n' \
           '<p>This is a simple application running on flask.</p>' \
           '<a href="https://www.python.org">Python Web</a>'
    r.set('about', json.dumps({
        'html': html_content,
        'time': time.time()
    }))
    return html_content

@app.route('/contact')
def contact():
    data = r.get('contact')
    if data is not None:
        data = json.loads(data)
        if time.time() - data['time'] <= 600:
            return data['html']
    
    html_content = '<a href="mailto:C23387203@mytudublin.ie">C23387203@mytudublin.ie</a>\n' \
           '<p>Student Email</p>'
    r.set('contact', json.dumps({
        'html': html_content,
        'time': time.time()
    }))
    return html_content
