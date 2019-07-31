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
    docker build -t server/app .
    ```
 4. Docker run server
    ```shell script
    docker run -d -p 4040:4040 server/app
    # Test if mappworksorks
    docker run --net host -p 4040:4040 server/app
    ```
 5. Check Server Port in Ubuntu
    ```shell script
    sudo lsof -t -i:4040
    sudo kill "The PID"
    ``` 
6. Docker Group
    ```shell script
    sudo groupadd docker
    sudo usermod -aG docker $USER
    newgrp docker
    ```