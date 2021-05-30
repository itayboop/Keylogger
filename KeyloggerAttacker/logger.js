const net = require('net');
const fs = require('fs');

function ReceiveConnection(socket) {
	var ostream = fs.createWriteStream("log.txt", {'flags':'a'});

	socket.on('end', () => {
		socket.pipe(socket);
		ostream.close();
	});

	socket.on('data',function(data) {
		if(data == '8') {
			ostream.write("del", {'flags':'a'}); 
		}
		
		ostream.write(data, {'flags':'a'});
	});
}

var server = net.createServer(ReceiveConnection);
server.listen(process.env.PORT || 2303, () => { });
