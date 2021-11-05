function sc = dtmfscore(xx, hh)
xx = xx*(2/max(abs(xx)));
yy = conv(xx, hh);
sc = max(yy) >= 0.59;
end