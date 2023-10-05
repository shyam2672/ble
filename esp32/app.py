from flask import Flask, request, jsonify

app = Flask(__name__)

temperature_data = None

@app.route('/')
def index():
    return jsonify(temperature=temperature_data)

@app.route('/get_temperature', methods=['POST'])
def get_temperature():
    global temperature_data
    if request.method == 'POST':
        temperature_data = float(request.form['temperature'])


        return "Temperature data received and updated successfully."

if __name__ == '__main__':
    app.run(debug=True, host='localhost', port=5000)
