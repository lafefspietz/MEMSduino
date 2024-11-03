
% Use the instrument control app to see what com ports are  connected and
% try connecting and testing. You can also use the Arduino IDE to find out
% what port the Arduino is on.  Change the baud rate to 115200 to interact
% with the serial.  Just send numbers 1 through 9 down the serial to change
% the state.  

switch_controller = instrfind('Type', 'serial', 'Port', 'COM10', 'Tag', '');

% Create the serial port object if it does not exist
% otherwise use the object that was found.
if isempty(switch_controller)
    switch_controller = serial('COM10');
else
    fclose(switch_controller);
    switch_controller = switch_controller(1);
end

fopen(switch_controller);
switch_controller.BaudRate = 9600;

%% bouncing lights test pattern

while true
    for n = 1:9
       fprintf(switch_controller,int2str(n))
       pause(0.05);
    
    end
    
    for n = 1:9
        
       fprintf(switch_controller,int2str(10-n))
       pause(0.05);
    
    end
end


%%  Step switch and take trace

for n = 1:9 
    smatrix.switch1 = n;    
    fprintf(switchotron1,int2str(smatrix.switch1));
    pause(2);
    % take and save trace here

end
