
void main() async {
  Uri apiUrl = Uri.parse("https://swapi.co/api/people/1");
  HttpClientRequest request = await new HttpClient().getUrl(apiUrl);
  HttpClientResponse response = await request.close();

  Stream resStream = response.transform(UTF.decoder);

  await for (var data in resStream) {
    print(data);
  }
}