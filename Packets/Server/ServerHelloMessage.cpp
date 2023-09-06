#include "Stream/ByteStream.cpp"

class ServerHelloMessage {
public:
	ByteStream Stream;

	encode(int sock) {
		Stream.writeInt(24);

		for (int i = 0; i <= 24, i++)
			Stream.writeBytes(0xFF); // SessionKey

		process(sock);
	}

	void process(int sock) {
		Stream.send(20108, sock);
	}
};