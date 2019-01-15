program desea_continuar;
var a:char;
begin
      a:='N' ;
      while(a<>'S')do 
      begin
      	   writeln ('desea continuar') ;
           read (a) ;
           if (a='S')then
           begin
                writeln ('repeticion') ;
           end
           else
           begin 
                if((a<>'N')and(a<>'S'))then
                begin
                     writeln ('responda S o N') ;
                end;     
           end;
      end;
end.
