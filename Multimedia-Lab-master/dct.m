function [result] = dct(img, q)

    img = double(img);
    q = abs(q - 101);

    [row colums] =  size(img);

    t = dctmtx(row);
    m = double(img);

    d = t * m * transpose(t);

    % quatization
    d = d/q;
    
    result = d;
    
end