from flask import Flask
from flask import request
from flask import Response
import msgpack
import time
import json 


form="""<!DOCTYPE html>   \
<html>                  \
<body>                  \
                        \
<form action="/data"  method="post">\
new datablock: <textarea\
       cols="100" \
       rows="20" \
       style="width:200px; height:50px;" \
       name="datablock" \
       id="datablock" \
       value=""></textarea><br>\
<input type="submit" value="Submit">\
</form>"""
body="""<p> Current content of datablock:</p>"""

footer="""</body>\
</html>"""

app = Flask(__name__)
def EncodeMessage(payload):
    return(msgpack.packb(payload))

def DecodeMessage(payload):
    return(msgpack.unpackb(payload))

@app.route('/')
def hello_world():
    return 'ISWiFi Mock - dockerized version'
    
@app.route('/data', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        app.datablock=json.loads(request.form['datablock'])
    return Response(str(app.datablock),mimetype='application/json')


@app.route('/msgpack')
def msgpack1():
    return Response(msgpack.packb("qqq"))

@app.route('/msgpack1')
def msgpack2():
    return Response(msgpack.packb(-250))


######################
#######  Time  #######
######################

@app.route('/Time/Time',methods=['GET', 'POST'])
def Param1000():
    if request.method == 'POST':
        app.timeshift=DecodeMessage(request.get_data())-time.time()
        return Response()
    else:
        return Response(EncodeMessage(int(time.time()+app.timeshift)),mimetype='application/msgpack')   

@app.route('/Time/SystemStartTime')
def Param1001():
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["SystemStartTime"]),mimetype='application/msgpack')

        
@app.route('/Time/SystemUptime')
def Param1002():
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["SystemUptime"]),mimetype='application/msgpack')

######################
#### Runtime   #######
######################

@app.route('/Runtime/LastIgnition')
def Param1100():
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["LastIgnition"]),mimetype='application/msgpack')

@app.route('/Runtime/StateUptime')
def Param1101():
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["StateUptime"]),mimetype='application/msgpack')

@app.route('/Runtime/State')
def Param1102():
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["State"]),mimetype='application/msgpack')

######################
#######   Errors #####
######################


@app.route('/Errors/Lockout')
def Param1200():
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["Lockout"]),mimetype='application/msgpack')

@app.route('/Errors/LastErrorTime')
def Param1201():
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["LastErrorTime"]),mimetype='application/msgpack')


@app.route('/Errors/LastError')
def Param1202(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["LastError"]),mimetype='application/msgpack')


@app.route('/Errors/LastLockoutReleseTime')
def Param1203(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["LastLockoutReleseTime"]),mimetype='application/msgpack')


@app.route('/Errors/ErrorList',methods=['GET', 'DELETE'])
def Param1204(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["ErrorList"]),mimetype='application/msgpack')
    if request.method == 'DELETE':
        app.datablock["ErrorList"]=[]



######################
#### Properties ######
######################


@app.route('/Properties/ID')
def Param1300(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["ID"]),mimetype='application/msgpack')


@app.route('/Properties/Firmware')
def Param1301(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["Firmware"]),mimetype='application/msgpack')


@app.route('/Properties/Hardware')
def Param1302(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["Hardware"]),mimetype='application/msgpack')


@app.route('/Properties/LastChange')
def Param1303(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["LastChange"]),mimetype='application/msgpack')


@app.route('/Properties/Changes',methods=['GET', 'DELETE'])
def Param1304(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["Changes"]),mimetype='application/msgpack')
    if request.method == 'DELETE':
        app.datablock["Changes"]=[]


@app.route('/Properties/Log',methods=['GET', 'DELETE'])
def Param1305(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["PropertiesLog"]),mimetype='application/msgpack')


@app.route('/Properties/PermLog')
def Param1306(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["PermLog"]),mimetype='application/msgpack')


@app.route('/Properties/Settings')
def Param1307(): 
    if request.method == 'GET':
        return Response(EncodeMessage([["/ISM0-10/Available",str(app.datablock["Available"])],["/Time/SystemStartTime",str(app.datablock["SystemStartTime"])],["/Modbus/GatewayTimeout",str(app.datablock["ModbusGatewayTimeout"])]]),mimetype='application/msgpack')


@app.route('/Properties/UART1',methods=['GET', 'POST'])
def Param1308(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["UART1"]),mimetype='application/msgpack')
    if request.method == 'POST':
        app.datablock["UART1"]=DecodeMessage(request.get_data())
        return Response()


@app.route('/Properties/UART2',methods=['GET', 'POST'])
def Param1309(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["UART2"]),mimetype='application/msgpack')
    if request.method == 'POST':
        app.datablock["UART2"]=DecodeMessage(request.get_data())
        return Response()


@app.route('/Properties/APIversion')
def Param1310(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["APIversion"]),mimetype='application/msgpack')


######################
####### QUERY  #######
######################


@app.route('/Querry/Interval',methods=['GET', 'POST'])
def Param1400(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["Interval"]),mimetype='application/msgpack')
    if request.method == 'POST':
        app.datablock["Interval"]=DecodeMessage(request.get_data())
        return Response()


######################
####### MODBUS #######
######################


@app.route('/Modbus/Address',methods=['GET', 'POST'])
def Param1500(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["ModbusAddress"]),mimetype='application/msgpack')
    if request.method == 'POST':
        app.datablock["ModbusAddress"]=DecodeMessage(request.get_data())
        return Response()


@app.route('/Modbus/GatewayTimeout',methods=['GET', 'POST'])
def Param1501(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["ModbusGatewayTimeout"]),mimetype='application/msgpack')
    if request.method == 'POST':
        app.datablock["ModbusGatewayTimeout"]=DecodeMessage(request.get_data())
        return Response()



######################
#######   ISM  #######
######################



@app.route('/ISM010_all')
def Param999(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["ISM010_all"]),mimetype='application/msgpack')


@app.route('/ISM010_available')
def Param998(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["ISM010_available"]),mimetype='application/msgpack')


@app.route('/ISM010_restart',methods=['GET', 'POST'])
def Param2000(): 
    if request.method == 'POST':
        app.datablock["ISM010_available"]="false"
        if (DecodeMessage(request.get_data())==b"123"):
            return Response(EncodeMessage("OK"))
        else:
            return Response(EncodeMessage("Wrong code - expeced 123 got:"+str(DecodeMessage(request.get_data()))),mimetype='application/msgpack')
    else:
        return Response("GET received")

@app.route('/ISM010_<int:register>',methods=['GET', 'POST'])
def registers(register):
    try:
        app.ISMparams[register]
    except:
        return Response("",404)
    if request.method == 'POST':
        app.ISMparams[register]=DecodeMessage(request.get_data())
        return Response()
    else:
        return Response(EncodeMessage(app.ISMparams[register]),mimetype='application/msgpack')


######################
#######   FILES ######
######################



# @app.route('/File/{Filename}')
# def Param1701(): 
#     if request.method == 'GET':
#         return Response(EncodeMessage(app.datablock["/File/{Filename}"]))

@app.route('/FileList')
def Param1700(): 
    if request.method == 'GET':
        return Response(EncodeMessage(app.datablock["FileList"]),mimetype='application/msgpack')


if __name__ == '__main__':
    app.datablock=json.loads("""\
    {\
        "SystemStartTime" : 1523304922,\
        "LastIgnition" : 1523307009,\
        "SystemUptime" : 3666,\
        "StateUptime" : 66,\
        "State" : "IDLE",\
        "Lockout" : true,\
        "LastErrorTime" : 1523307029,\
        "LastError" : 241,\
        "LastLockoutReleseTime" : 1523307030,\
        "ErrorList" : [[1523307029,241,"F1"],[1523307035,242,"F2"]],\
        "ID" : "Identifiaction",\
        "Firmware" : "3003",\
        "Hardware" : "1001",\
        "LastChange" : [1523307030, "Param3", "6", "5"],\
        "Changes" : [[1523307020, "Param2", "1", "6"],[1523307030, "Param3", "6", "5"]],\
        "PropertiesLog" : [[1523307010, "Time entry1"],[1523307020, "Time entry2"],[1523307040, "Time entry3"]],\
        "PermLog" :    [[1523307010, "Permlog Time entry1"],[1523307020, "Permlog Time entry2"],[1523307040, "Permlog Time entry3"]],\
        "UART1" : "96008N1",\
        "UART2" : "96008N1",\
        "APIversion" : "1.0",\
        "Interval" : 1000,\
        "ModbusAddress" : 1,\
        "ModbusGatewayTimeout":1500,\
        "ISM010_available":true,\
        "ISM010_all":[[1,1],[2,4],[3,6]],\
        "FileList":["PermLog", "EvLog", "ErrLog"],\
        "Available":true\
    }\
    """)
    q=list(range(1,17))+list(range(501,535))+list(range(1000,1002))
    app.ISMparams=dict(zip(q,q))
    app.timeshift=0
    app.run(debug=True,host='0.0.0.0')
