function C = C(u,v,r)
%C
%    C = C(U,V,R)

%    This function was generated by the Symbolic Math Toolbox version 7.1.
%    09-Mar-2019 14:41:48

t2 = u.*1.611e1;
C = reshape([0.0,0.0,r.*5.29125e-1+v.*2.411e1,0.0,0.0,-t2,r.*(-5.29125e-1)-v.*2.411e1,t2,0.0],[3,3]);
