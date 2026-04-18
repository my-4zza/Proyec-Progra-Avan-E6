module seguidor_linea (
    input sensor_izq,   
    input sensor_der,   
    input sensor_movimiento, 

   
    output reg IN1, 
    output reg IN2, 
    output reg IN3, 
    output reg IN4, 
    
 
    output ENA,     
    output ENB      
);

  
    assign ENA = 1'b1;
    assign ENB = 1'b1;

   
    always @(*) begin
       
        
        if (sensor_movimiento == 1'b1) begin
            
          
            case ({sensor_izq, sensor_der})
              
                2'b00: begin 
                    IN1 = 1'b0; IN2 = 1'b0;
                    IN3 = 1'b0; IN4 = 1'b0;
                end
                
                
                2'b01: begin 
                    IN1 = 1'b1; IN2 = 1'b0; 
                    IN3 = 1'b0; IN4 = 1'b0; 
                end
                
                
                2'b10: begin 
                    IN1 = 1'b0; IN2 = 1'b0; 
                    IN3 = 1'b1; IN4 = 1'b0; 
                end
                
                
                2'b11: begin 
                    IN1 = 1'b1; IN2 = 1'b0; 
                    IN3 = 1'b1; IN4 = 1'b0; 
                end
                
              
                default: begin
                    IN1 = 1'b0; IN2 = 1'b0;
                    IN3 = 1'b0; IN4 = 1'b0;
                end
            endcase
            
        end else begin
           
            IN1 = 1'b0; IN2 = 1'b0;
            IN3 = 1'b0; IN4 = 1'b0;
        end
    end

endmodule
