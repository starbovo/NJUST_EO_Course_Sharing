%% 定义输入信号x
clear; clc;
t = linspace(-5,5,1000); % 定义时间范围
x = sinc(5*t); % 定义 x
x_trans = sinc(5*t) + exp(-100i*t).*sinc(5*t) + exp(100i*t).*sinc(5*t); % 对x进行频移
N = length(x_trans); % 信号长度

X = fftshift(fft(x_trans)); % 傅里叶变换

%% 绘制输入信号和傅里叶变换结果
figure('Name', '输入信号和傅里叶变换');
subplot(2,2,1);
plot(t,x);
title('输入信号');
xlabel('时间');
ylabel('幅值');

subplot(2,2,2);
plot(t,x_trans);
title('输入信号频移后');
xlabel('时间');
ylabel('幅值');

subplot(2,2,3);
f = linspace(-N/2, N/2-1, N) * (1/(t(2)-t(1))) / N; % 频率向量
XX = fftshift(fft(x))/N;
plot(f,abs(XX));
title('傅里叶变换');
xlabel('频率');
ylabel('幅值');

subplot(2,2,4);
plot(f,abs(X));
title('频移后傅里叶变换');
xlabel('频率');
ylabel('幅值');

%% 设计低通滤波器
fc = 5; % 截止频率
fs = 1/(t(2)-t(1)); % 采样频率
order = 50; % 滤波器阶数
b = fir1(order, fc/(fs/2)); % 生成滤波器系数
y = filter(b, 1, x_trans); % 对x_trans进行滤波
Y = fftshift(fft(y)); % 对滤波结果进行傅里叶变换

%% 绘制输入输出和傅里叶变换结果
fig = figure('Name', '输入输出和傅里叶变换结果');
set(fig, 'Position', [100, 100, 600, 800]);
subplot(4,1,1);
plot(t,x_trans);
title('原始信号');
xlabel('时间');
ylabel('幅值');

subplot(4,1,2);
plot(t,y);
title('滤波后的信号');
xlabel('时间');
ylabel('幅值');

subplot(4,1,3);
plot(f,abs(X));
title('输入信号的傅里叶变换');
xlabel('频率');
ylabel('幅值');

subplot(4,1,4);
plot(f,abs(Y));
title('输出信号的傅里叶变换');
xlabel('频率');
ylabel('幅值');

figure('Name', '滤波器的频率响应');
freqz(b,1); % 绘制滤波器的频率响应
title('滤波器');
xlabel('频率');
ylabel('幅值');
%% 调制和解调
% 调制
fc = 20000; % 载波频率
fs = 50000;
c = sin(2*pi*fc*t);
y = y + sin(pi*fc*t)/5;
m = y .* c;

figure('Name', '信号的调制');
subplot(2,2,1)
plot(t,y);
title('调制前的信号');
xlabel('时间');
ylabel('幅值');

subplot(2,2,2)
Y = fftshift(fft(y));
plot(f, abs(Y));
title('调制前的信号的频谱');
xlabel('频率');
ylabel('幅值');

subplot(2,2,3)
plot(t,m);
title('调制后的信号');
xlabel('时间');
ylabel('幅值');

subplot(2,2,4)
M = fftshift(fft(m));
plot(f, abs(M));
title('调制后的信号的频谱');
xlabel('频率');
ylabel('幅值');

% 解调
y_demod = m .* sin(2*pi*fc*t);
baseband_sig = y_demod .* sin(2*pi*fc*t);
envelope = abs(hilbert(baseband_sig));

% 滤波
[b, a] = butter(6, 0.5, 'low');
z = filter(b, 1, y_demod);

% 绘制解调前后的信号和频谱
figure('Name', '解调前后的信号和频谱');
subplot(3,2,1);
plot(t,m);
title('解调前的信号');
xlabel('时间');
ylabel('幅值');

subplot(3,2,3)
M = fftshift(fft(m));
plot(f, abs(M));
title('解调前的信号的频谱');
xlabel('频率');
ylabel('幅值');

subplot(3,2,2);
plot(t, y_demod);
title('解调后的信号');
xlabel('时间');
ylabel('幅值');

subplot(3,2,4);
Y_demod = fftshift(fft(y_demod));
plot(f, abs(Y_demod));
title('解调后信号的频谱');
xlabel('频率');
ylabel('幅值');

subplot(3,2,5);
plot(f, abs(fftshift(fft(z))));
title('滤波后信号的频谱');
xlabel('频率');
ylabel('幅值');
h = get(gca, 'position'); 
h(3)=2.4*h(3);
set(gca, 'position', h);