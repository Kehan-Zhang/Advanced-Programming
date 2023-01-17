# Document API for Library

## Webcam.js

### Attribute

| Name        | Html                                    | Description                                              |
| ----------- | --------------------------------------- | -------------------------------------------------------- |
| originVideo | document.getElementById("originVideo"); | Play original video from webcam                          |
| filterVideo | document.getElementById("filterVideo"); | Play video under filter effects from webcam              |
| takePhoto   | document.getElementById("takePhoto");   | Take photo under filter effect button                    |
| clear       | document.getElementById("clear");       | Remove all photos from photo gallery button              |
| photos      | document.getElementById("photos")       | Photo gallery                                            |
| canvas      | document.getElementById("canvas");      | Canvas for showing picture                               |
| filter      | document.getElementById("filter");      | Filter options(blur, grayscale, invert, sepia, contrast) |



### Function

| Name                                              | Description                                                  |
| ------------------------------------------------- | ------------------------------------------------------------ |
| start()                                           | Ask permission for webcam and init video stream              |
| takePicture()                                     | Take photo under filter effect and save to photo gallery     |
| handleErr()                                       | Print erro log on console                                    |
| filter.addEventListener("change", function(e) {}) | Callback function: when selected option in filters change, filter will be updated on filterVideo |
| takePhoto("click", function(e) {})                | Callback function: when button takePhoto is clicked, a photo under filter's effect will be taken and add into photo gallery |
| clear("click", function(e) {})                    | Callback function: when button clear is clicked, all photos in photo gallery will be removed |





# Instructions

## Emescripten

1. download emsdk

```shell
git clone https://github.com/emscripten-core/emsdk.git //download emsdk
```

2. enter emsdk folder
```shell
cd emsdk
```

3. install the lastest version and activate
```shell
./emsdk install latest
./emsdk activate latest
```

4. enter shell with emsdk environment
```shell
source ./emsdk_env.sh
```

5. emescripten with function exposed
```shell
emcc ClimbStairs.cpp -o /Users/kehanzhang/Desktop/Workspace/Projects/lab-1-emscripten-Kehan- Zhang/Code/ClimbStairs.js -s EXPORTED_FUNCTIONS="['_climbStairs']" -s EXPORTED_RUNTIME_METHODS='["ccall"]'
```

6. emescripten with optimization
```shell
emcc -O3 ClimbStairs.cpp -o /Users/kehanzhang/Desktop/Workspace/Projects/lab-1-emscripten-Kehan- Zhang/Code/ClimbStairs.js -s EXPORTED_FUNCTIONS="['_climbStairs']" -s EXPORTED_RUNTIME_METHODS='["ccall"]'
```

7. emescripten with mutithread
```shell
emcc -std=c++11 -pthread -s PROXY_TO_PTHREAD -s ALLOW_MEMORY_GROWTH=1 -s NO_DISABLE_EXCEPTION_CATCHING -s EXIT_RUNTIME=1 ./*.cpp -o test.js
```

8. emescripten with websocket
```shell
emcc -lwebsocket.js -std=c++11 -pthread -s PROXY_TO_PTHREAD -s ALLOW_MEMORY_GROWTH=1 -s NO_DISABLE_EXCEPTION_CATCHING -s EXIT_RUNTIME=1 ./*.cpp -o test.js
```

9. open client window using Chrome for websocket test

```shell
open -n /Applications/Google\ Chrome.app/ --args --disable-web-security  --user-data-dir=/Users/kehanzhang/MyChromeDevUserData/
```



## Electron

1. Check if npm and node is installed

```shell
npm -v
node -v
```

2. Initialize npm project

```shell
npm init
```

3. Install Electron into app's devDependencies

```shell
npm install electron --save-dev
```

4. Add electron . to the start command in the scripts field of package.json

```json
"scripts": {
    "start": "electron-forge start",
  	...
  },
```

5. Run electron app

```shell
npm run start
```

6. Install electron-builder

```shell
npm install --save-dev electron-builder
node_modules/.bin/electron-builder -h
```

7. Packaging

```shell
node_modules/.bin/electron-builder -l AppImage # Linux
node_modules/.bin/electron-builder -w nsis # Windows
node_modules/.bin/electron-builder -m dmg # MacOS
```

