Conv2D

tf.nn.conv2d(input, filter, strides, padding, use_cudnn_on_gpu = None, name = None)

input : [batch, in_height, in_width, in_channel]

filter : [filter_height, filter_width, in_channels, out_channels]


두 개의 in_channel의 값은 같아야 함. channel은 색. 3이면 rgb

out_channel은 conv filter의 개수로 볼 수 있음.
