import 'dart:io';
import 'dart:convert';

main() async {
  var apiUrl = Uri.parse('https://jsonplaceholder.typicode.com/posts');
  var client = HttpClient();

  //1. Create request
  HttpClientRequest request = await client.postUrl(apiUrl)

  //2. Add things to request
  var payload = {
    'title':'Post 1',
    'content': 'lorem ipsum dolor sit amet',
  };
  request.write(json.encode(payload));

  //3. Send request
  HttpClientResponse response = await request.close()

  //4. handle response
  var resStream  =response.transform(Utf8Decoder());
  await for(var data in resStream){
    print('Received data: $data')
  }
}