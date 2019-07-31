# Dcoker Setup for dart server

1. Create Dockerfile
    ```shell script
    touch Dockerfile
    ```
 2. Inside DockerFile
    ```Dockerfile
    FROM google/dart-runtime
    ```
 3. Docker Build
    ```shell script
    sudo docker build -t server/app .
    ```
 4. Docker run server
    ```shell script
    sudo docker run -d -p 4040:4040 server/app
    # Test if mappworksorks
    sudo docker run --net host -p 4040:4040 server/app
    ```
 5. Check Server Port in Ubuntu
    ```shell script
    sudo lsof -t -i:4040
    sudo kill "The PID"
    ``` 