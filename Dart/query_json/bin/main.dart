import 'dart:io';
import 'dart:async';
import 'dart:convert';

void main() async {
  Uri apiUrl = Uri.parse("https://swapi.co/api/people/1");
  HttpClientRequest request = await new HttpClient().getUrl(apiUrl);
  HttpClientResponse response = await request.close();

  Stream resStream = response.transform(utf8.decoder);

  await for (var data in resStream) {
    print(data);
  }
}