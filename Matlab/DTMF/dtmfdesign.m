function hh = dtmfdesign(fb, L, fs)
n = repmat((0:L-1)', 1, size(fb,2));
f = repmat(fb, L, 1);
p = n .* f;
hh = cos(2*pi*p/fs);
gains = hh .* exp(-1i*2*pi*p/fs);
gains = abs(sum(gains, 1));
hh = hh ./ repmat(gains, L, 1);
end