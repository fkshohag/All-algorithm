Problem-1: 
* Amplitude modulation
fs = 100;
t = (0:1/fs:100)';
fc = 10;
x = sin(2*pi*t);
ydouble = ammod(x,fc,fs);
ysingle = ssbmod(x,fc,fs);
sa = dsp.SpectrumAnalyzer('SampleRate',fs, ...
'PlotAsTwoSidedSpectrum',false, ...
'YLimits',[-60 40]);
sa(ydouble)
sa(ysingle)

* time domain plot:
Fc = 200;
Fs= 4000;
t = (0 : 1 / Fs : 1);
x = sin(2*pi*t);
y = ammod(x, Fc, Fs);
plot(y);
title('Amplitude Modulation');
xlabel('Time(sec)');
ylabel('Amplitude');

* Amplitude Demodulation
fc = 1000;
fs = 8000;
t = (0:1/fs:0.01)';
s = sin(2*pi*300*t)+2*sin(2*pi*600*t);
y = ammod(s,fc,fs);
z = amdemod(y,fc,fs);
plot(t,s,'c',t,z,'b--')
legend ('Original Signal','Demodulated Signal')
xlabel('Time (s)')
ylabel('Amplitude')

* Frequency Modulation
fs = 1000;
fc = 200;
t = (0:1/fs:0.2)';
x = sin(2*pi*30*t)+2*sin(2*pi*60*t);
fDev = 50;
y = fmmod(x,fc,fs,fDev);
plot(t,x,'c',t,y,'b--')
xlabel('Time (s)')
ylabel('Amplitude')
legend('Original Signal','Modulated Signal')

* FM Modulate and Demodulate Sinusoidal Signal
fs = 1000;
fc = 200;
t = (0:1/fs:0.2)';
x = sin(2*pi*30*t)+2*sin(2*pi*60*t);
fDev = 50;
y = fmmod(x,fc,fs,fDev);
z = fmdemod(y,fc,fs,fDev);
plot(t,x,'c',t,z,'b--');
xlabel('Time (s)')
ylabel('Amplitude')
legend('Original Signal','Demodulated Signal')