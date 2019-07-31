import "dart:io";

Future main() async {
  var server = await HttpServer.bind(
    InternetAddress.loopbackIPv4,
    4040,
  );
  await for (HttpRequest request in server) {
    request.response.write('Hello, world!');
    await request.response.close();
  }
}

