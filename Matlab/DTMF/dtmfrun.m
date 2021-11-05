function keys = dtmfrun(xx,L,fs)
freqs = [697,770,852,941,1209,1336,1477,1633];
dtmf.keys = [ '1','2','3','A';
    '4','5','6','B';
    '7','8','9','C';
    '*','0','#','D'];
hh = dtmfdesign( freqs,L,fs );
[nstart,nstop] = dtmfcut(xx,fs);
keys = [];
for kk=1:length(nstart)
    x_seg = xx(nstart(kk):nstop(kk));
    scores = [];
    for ff=1:8
        scores(ff) = dtmfscore(x_seg, hh(:, ff));
    end
    [val_1, ii] = max(scores(1:4));
    [val_2, jj] = max(scores(5:8));
    keys(kk) = dtmf.keys(ii, jj);
end
keys = char(keys);
end