import csv
import pandas as pd

def columns(path_to_file):
    '''returns the list of column header from a csv file'''
    with open(path_to_file) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        list_of_columns = []
        for row in csv_reader:
            list_of_columns.append(row)
            break 
    
    print("List of column names : ", list_of_columns[0])
    print("Count of columns : ", len(list_of_columns[0]))

def delete_columns():
    data = pd.read_csv("./data.csv")
    del_col = ["Internal1/Assignment", "Mid Term", "Internal2/Attendance", "End Term", "Grade", "Sr No."]
    data.drop([x for x in del_col], inplace=True, axis=1)
    return data


if __name__ == "__main__":
    columns('./data.csv')
    col_list = delete_columns()
    print(type(col_list))
    col_list.to_csv("./processed_data.csv", index=False, header=False)