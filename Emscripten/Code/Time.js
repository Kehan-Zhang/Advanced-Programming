var addModule = Module.onRuntimeInitialized = function() {
    for (var i = 0; i < 1000; i++) {
        var start = performance.now();
        var result = Module.ccall('climbStairs', 'number', ['int'], [30]);
        var end = performance.now();
        var runtime  = (end - start) / 1000;
        console.log(runtime.toFixed(4));
    }
}