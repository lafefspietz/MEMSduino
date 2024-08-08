
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
switch_controller.BaudRate = 115200;

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
%% Set up Network Analyzer

% GPIB address is 19, address of USB controller which converts to GPIB is
% 8. 
obj.AgilentVNA = instrfind('Type', 'gpib', 'BoardIndex', 8, 'PrimaryAddress', 19, 'Tag', '');

% Create the GPIB object if it does not exist
% otherwise use the object that was found.
if isempty(obj.AgilentVNA)
    obj.AgilentVNA = gpib('KEYSIGHT', 8, 19);
else
    fclose(obj.AgilentVNA);
    obj.AgilentVNA = obj.AgilentVNA(1);
end

% the following fixed a problem with the buffer not getting all the data
% before it quits. this was a hard to find problem, and it has to have this
% hack inserted before the device gets openned
obj.AgilentVNA.InputBufferSize = 10000;

% Connect to instrument object, obj1.
fopen(obj.AgilentVNA);


% Read the start and stop frequency and number of points, and put them all
% into an object, create a vector of the frequencies, which are in Hz
vna.f_start = str2num(query(obj.AgilentVNA, 'SENS:FREQ:STAR?','%s\n','%c'));
vna.f_stop  = str2num(query(obj.AgilentVNA, 'SENS:FREQ:STOP?','%s\n','%c'));
vna.npts    = str2num(query(obj.AgilentVNA, 'SENS:SWE:POIN?','%s\n','%c'));
f = linspace(vna.f_start,vna.f_stop,vna.npts);
%%  Step switch and take trace

for index = 1:10
    for n = 1:9

    
        smatrix.switch1 = n;    
        fprintf(switchotron1,int2str(smatrix.switch1));
        pause(2);
        % take and save trace here
    
    end
end