function signal = dtmfdial(keyNames, Fs)
dtmf.keys = [ '1','2','3','A';
    '4','5','6','B';
    '7','8','9','C';
    '*','0','#','D'];
dtmf.colTones = ones(4,1) * [1209,1336,1477,1633];
dtmf.rowTones = [697;770;852;941] * ones(1,4);
tlen = Fs * 0.2;
slen = Fs * 0.05;
alen = tlen+slen;
signal = zeros(1,alen*length(keyNames));
n = 2*pi*(0:tlen-1)/Fs;
for x = 1:length(keyNames)
    [ii, jj] = find(keyNames(x) == dtmf.keys);
    signal(alen*(x-1)+1:alen*(x-1)+tlen) = cos(n*dtmf.colTones(ii,jj))+cos(n*dtmf.rowTones(ii,jj));
end
end