xx = bell([250 350], 3, 1, 5, 11025);

soundsc(xx, 11025);

function xx = bell(ff, Io, tau, dur, fsamp)
    tt = 0:(1/fsamp):dur;
    At = bellenv(tau, dur, fsamp);
    It = At * Io;
    fi = ff(1) - It * ff(2) .* sin(2*pi*ff(2)*tt) + cos(2*pi*ff(2)*tt);
    xx = At .* cos(2*pi*ff(1)*tt+(It .* cos(2*pi*ff(2)*tt)));
    plot(tt, fi), grid on
end
