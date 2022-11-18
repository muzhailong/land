## Tensorflow Pluggable Device
#### DESC
Tensorflow Pluggable Device Demo 实现，主要为了学习

#### Usage
<pre>
mkdir build && cd build
cmake -GNinja --DProtobuf_INCLUDE_DIR={protobuf 头文件目录} ..
cp ./src/libland.so {env目录}/lib/python3.8/site-packages/tensorflow-plugins
</pre>

#### Note
- protobuf 版本必须和tensorflow匹配

#### Resources
- https://github.com/jzhoulon/community/blob/plugin_tutorial/rfcs/20200624-pluggable-device-for-tensorflow/tutorial.md#Kernels/Ops
- https://github.com/jzhoulon/community/tree/plugin_tutorial/rfcs/20200624-pluggable-device-for-tensorflow
