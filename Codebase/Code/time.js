var addModule = Module.onRuntimeInitialized = function() {
    for (var i = 0; i < 1000; i++) {
        var start = performance.now();
        Module.ccall('test');
        var end = performance.now();
        var runtime  = (end - start) / 1000;
        console.log(runtime.toFixed(4));
    }
}