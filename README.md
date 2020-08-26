# digital-clock-Atmega16
This is a full clock system running in real time using Atmega16 as a microcontroller and interface it with an LCD to show date and time. The system uses an implemented scheduler to ensure that all tasks are running in real time and maintain the priorities of the tasks in runtime. Also all modules are layered in three basic layers:

**MCAL:** The layer where all basic drivers of the microcontroller exists and it contains (`DIO`, `interrupts`, `timer`).

**HAL:** The layer where drivers of the interfaced devices exists and it contains (`LCD`).

**APP:** The layer where the application drivers that uses the bellowed drivers exists and it contains (`clock`).

## Modes of operation
The clock has two modes of operation:
1.	Running mode
2.	Setting mode

### Running Mode:
In running mode, every one second the second's digits will increase by one. If seconds reaches 59 then the new second will be 00 and minute's digits will increase by one. If minutes reaches 59 then the new minute will be 00 and the hour's digits will increase by one. If hours reaches 12 then the new hour will be 01. When hours reaches 12, the PM/AM flag will toggle. When time changes from PM to AM then the days will increase by one. If day reaches the maximum number of days the days will be 00 and the months will increase by one. The maximum number of days is depending on the month. When months reach 12, the next month will be 01 and the year will increase by one. There is no limit for the available number of years.

### Setting Mode:
To start setting mode you press MODE button. Now you are available to edit hours by pressing INC button to increase hours and DEC button to decrease hours. By pressing on MODE button again, you can then edit minutes and so on.

| Number of presses | Action |
| --- | --- |
| 1 | Enter setting mode and edit Hours |
| 2 | Edit minutes |
| 3 | Edit seconds |
| 4 | Edit days |
| 5 | Edit months |
| 6 | Edit years |
| 7 | Back to running mode starting from the set values |

## Components:
1. Atmega16
2. Three push buttons
3. 2×16 LCD (LM016L)

> Youtube video of the project

<a href="http://www.youtube.com/watch?feature=player_embedded&v=EORuZf2P008
" target="_blank"><img src="http://img.youtube.com/vi/EORuZf2P008/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="560" height="315" border="10" /></a>


## Future work:
- [x] ~~Add setting mode.~~
- [ ] Add alarm mode.
- [ ] Add seven-segment display with two digits to show PM/AM.
- [ ] Re-implement the system with FreeRTOS.
- [ ] Implement the system on hardware with PCB.
