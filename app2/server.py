from flask import Flask
from flask import request, jsonify
from flask_cors import CORS

app = Flask(__name__)
cors = CORS(app)

# basic route
@app.route("/",methods=['POST'])

def main():
	content = request.get_json()
	age = content['age']
	name = content['name']
	data = {}
	if age.isdigit() == True:
		age = int(content['age'])
		if age >= 65:
			data= {'name': name, 'message' : 'You are a senior'}
		else:
			data= {'name': name, 'message' : 'You are not a senior'}
	else:
		data= {'name': name, 'message' : 'Age is not a number'}
	return jsonify(data)


if __name__ == "__main__":
   app.run()
