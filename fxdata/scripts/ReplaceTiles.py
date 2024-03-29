import csv
import sys



# Define the replacement table dictionary
replacement_table = {
"-1":"-1",
"0":"0",
"1":"1",
"2":"2",
"3":"3",
"4":"4",
"5":"5",
"6":"6",
"7":"7",
"8":"8",
"9":"9",
"10":"10",
"11":"11",
"12":"12",
"13":"13",
"14":"14",
"15":"15",
"16":"16",
"17":"17",
"18":"18",
"19":"19",
"20":"20",
"21":"21",
"22":"22",
"23":"23",
"24":"24",
"25":"25",
"26":"26",
"27":"27",
"28":"28",
"29":"51",
"30":"52",
"31":"50",
"32":"51",
"33":"52",
"34":"53",
"35":"54",
"36":"55",
"37":"56",
"38":"57",
"39":"58",
"40":"59",
"41":"60",
"42":"61",
"43":"62",
"44":"63",
"45":"64",
"46":"65",
"47":"66",
"48":"67",
"49":"68",
"50":"69",
"51":"70",
"52":"71",
"53":"72",
"54":"73",
"55":"74",
"56":"75",
"57":"76",
"58":"77",
"59":"78",
"60":"79",
"61":"80",
"62":"81",
"63":"82",
"64":"83",
"65":"84",
"66":"85",
"67":"86",
"68":"87",
"69":"88",
"70":"89",
"71":"90",
"72":"91",
"73":"92",
"74":"0", 
"75":"1", 
"76":"2", 
"77":"3", 
"78":"4", 
"79":"5", 
"80":"6", 
"81":"7", 
"82":"8", 
"83":"9", 
"84":"10",
"85":"11",
"86":"12",
"87":"13",
"88":"14",
"89":"15",
"90":"16",
"91":"17",
"92":"18",
"93":"19",
"94":"20",
"95":"21",
"96":"22",
"97":"23",
"98":"24",
"99":"25",
"100":"26",
"101":"27",
"102":"28",
"103":"29",
"104":"30",
"105":"31",
"106":"32",
"107":"33",
"108":"34",
"109":"35",
"110":"36",
"111":"37",
"112":"38",
"113":"39",
"114":"40",
"115":"41",
"116":"42",
"117":"43",
"118":"44",
"119":"45",
"120":"46",
"121":"47",
"122":"48",
"123":"49",
"124":"124",
"125":"125",
"126":"126",
"127":"127",
"128":"128",
"129":"51",
"130":"52"

}

# Get the input and output filenames from command line arguments
if len(sys.argv) < 3:
    print("Usage: python replace_numbers.py input_file output_file")
    sys.exit()

input_filename = sys.argv[1]
output_filename = sys.argv[2]


with open(input_filename, "r") as input_file, open(output_filename, "w", newline="") as output_file:

    csv_reader = csv.reader(input_file)
    csv_writer = csv.writer(output_file)
    

    for row in csv_reader:

        for i in range(len(row)):
            cell = row[i]
            
            if cell in replacement_table:
                row[i] = replacement_table[cell]
        
        csv_writer.writerow(row)