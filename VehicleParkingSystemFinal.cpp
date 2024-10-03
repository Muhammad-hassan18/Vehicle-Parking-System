#include <iostream>
#include <string>
using namespace std;

const int max_vehicles=4;
const int max_vehicles_per_type=1;
int count1=0,count2=0,count3=0,count4=0;

struct VEHICLE
{
string serialnumber;
char type;
};

class ParkingSystem
{
	private:
		VEHICLE Car[max_vehicles_per_type];
		VEHICLE Bus[max_vehicles_per_type];
		VEHICLE Rickshaw[max_vehicles_per_type];
		VEHICLE Motorbike[max_vehicles_per_type];
		int carCount;
        int busCount;
        int bikeCount;
        int rickshawCount;
    public:
    	ParkingSystem() : carCount(0), busCount(0), bikeCount(0), rickshawCount(0) {}

char asktask(char choice)
{
    ;
    cout << "Press P to park a vehicle/ R for moving out a vehicle/ S for showing stats/ Q for quitting" << endl;
    cin >> choice;
    return choice; 
}
void addvehicle(const string serialnumber,const char type)
{
	 if (carCount + busCount + bikeCount + rickshawCount >= max_vehicles)
	{
		cout<<"    "<<endl;
        cout << "Parking is full. Cannot add more vehicles." <<endl;
        cout<<"    "<<endl;
        return;
    }
    VEHICLE vehicle;
    vehicle.serialnumber = serialnumber;
    vehicle.type = type;
     
    if (type=='c'||type=='C')
	{
            if (carCount <max_vehicles_per_type)
			{
                Car[carCount++] = vehicle;
                cout<<"    "<<endl;
                cout << "Car with serial number " << serialnumber << " entered." <<endl;
                cout<<"    "<<endl;
                count1=count1+1;
            } 
			else 
			{
				cout << "Maximum limit reached for cars." <<endl;
            }
    }       
    else if (type=='b'||type=='B')
	{
            if (busCount < max_vehicles_per_type)
			{
                Bus[busCount++] = vehicle;
                cout<<"    "<<endl;
                cout << "Bus with serial number " << serialnumber << " entered." <<endl;
                cout<<"    "<<endl;
                count2=count2+1;
            } 
			else
			{
                cout << "Maximum limit reached for buses." <<endl;
            }
    } 
	else if (type=='M'||type=='m')
	{
            if (bikeCount < max_vehicles_per_type)
			{
                Motorbike[bikeCount++] = vehicle;
                cout<<"    "<<endl;
                cout << "Bike with serial number " << serialnumber << " entered." <<endl;
                cout<<"    "<<endl;
                count3=count3+1;
            }
			else
			{
                cout << "Maximum limit reached for bikes." <<endl;
            }
    } 
	else if (type=='r'||type=='R')
	{
            if (rickshawCount < max_vehicles_per_type)
			{
                Rickshaw[rickshawCount++] = vehicle;
                cout<<"    "<<endl;
                cout << "Rickshaw with serial number " << serialnumber << " entered." <<endl;
                cout<<"    "<<endl;
                count4=count4+1;
            }
			else
			{
                cout << "Maximum limit reached for rickshaws." <<endl;
            }
    } 
	else 
	{
        cout << "Invalid vehicle type." << std::endl;
    }
}
void removevehicle(string serialnumber)
{
    for (int i = 0; i < carCount; ++i)
    {
        if (Car[i].serialnumber == serialnumber)
		{
			cout<<"    "<<endl;
            cout << "Car with serial number " << serialnumber << " found. Charges: Rs. 150" <<endl;
            cout<<"    "<<endl;
            Car[i] = Car[--carCount];
            count1=count1-1;
            return;
        }
    }

    for (int i = 0; i < busCount; ++i)
	{
        if (Bus[i].serialnumber == serialnumber)
		{
			cout<<"    "<<endl;
            cout << "Bus with serial number " << serialnumber << " found. Charges: Rs. 200." <<endl;
            cout<<"    "<<endl;
            Bus[i] = Bus[--busCount];
            count2=count2-1;
            return;
        }
    }

    for (int i = 0; i < bikeCount; ++i)
	{
        if (Motorbike[i].serialnumber == serialnumber)
		{
			cout<<"    "<<endl;
            cout << "Bike with serial number " << serialnumber << " found. Charges: Rs.80" <<endl;
            cout<<"    "<<endl;
            Motorbike[i] = Motorbike[--bikeCount];
            count3=count3-1;
            return;
            }
        }

        for (int i = 0; i < rickshawCount; ++i)
		{
            if (Rickshaw[i].serialnumber == serialnumber) 
			{
				cout<<"    "<<endl;
                cout << "Rickshaw with serial number " << serialnumber << " found. Charges: Rs. 50" <<endl;
                cout<<"    "<<endl;
                Rickshaw[i] = Rickshaw[--rickshawCount];
                count4=count4-1;
                return;
            }
        }

        cout << "Vehicle with serial number " << serialnumber << " not found." <<endl;
    }
};
int main()
{
	ParkingSystem parkingsystem;
    string serialnumber;
	char type;
    char choice;
    
    
    while (true)
    {
        choice = parkingsystem.asktask(choice);
        
        if (choice == 'Q' || choice == 'q')
            break;

        switch (choice)
        {
            case 'p':
            case 'P':
                cout << "Enter the vehicle type (Press C for cars/B for buses/M for motorbikes/R for rickshaws)" << endl;
                cin >> type;
                cout << "Enter the vehicle's serial number" << endl;
                cin >> serialnumber;
                parkingsystem.addvehicle(serialnumber,type);
                break;
            case 'r':
            case 'R':
                cout << "Enter the vehicle's' serial number" << endl;
                cin >> serialnumber;
                parkingsystem.removevehicle(serialnumber);
                break;
            case 's':
			case 'S':
				cout<<"**************************************"<<endl;
	        	cout<<"**************************************"<<endl;
	         	cout<<"**************************************"<<endl;
	        	cout<<"**************************************"<<endl;
		        cout<<"                                      "<<endl;
		  	    cout<<"Total Cars parked = "<<count1<<endl;
				cout<<"Total buses parked = "<<count2<<endl;
				cout<<"Total Motorbikes parked = "<<count3<<endl;  
				cout<<"Total Rickshaws parked = "<<count4<<endl;     
				cout<<"                              "<<endl;
				cout<<"Total Vehicles parked in the area = "<<count1+count2+count3+count4<<endl;
				cout<<"                                      "<<endl;
				cout<<"**************************************"<<endl;
		        cout<<"**************************************"<<endl;
	        	cout<<"**************************************"<<endl;
	         	cout<<"**************************************"<<endl;
	        	cout<<"                                      "<<endl;
	        	break;
	        	
            default:
                cout << "Invalid input. Please try again" << endl;
                break;
        }
    }

    return 0;
}


