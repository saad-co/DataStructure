CREATE TABLE BloodSpecimen (
    specimen_no number(10) NOT NULL,
    b_grp varchar2(10) NOT NULL,
    status number check(
        status In (
            0
            or 1
        )
    ),
    dfind_ID number NOT NULL,
    M_id NOT NULL,
    primary key (specimen_number, b_group),
    FOREIGN KEY(M_id) REFERENCES Manager(M_id),
    FOREIGN KEY(dfind_ID) REFERENCES DiseaseFinder(dfind_ID)
);

INSERT into
    BloodSpecimen
VALUES
    (1001, 'B+', 1, 11, 101),
    (1002, 'O+', 1, 12, 102),
    (1003, 'AB+', 1, 11, 102),
    (1004, 'O-', 1, 13, 103),
    (1005, 'A+', 0, 14, 101),
    (1006, 'A-', 1, 13, 104),
    (1007, 'AB-', 1, 15, 104),
    (1008, 'AB-', 0, 11, 105),
    (1009, 'B+', 1, 13, 105),
    (1010, 'O+', 0, 12, 105),
    (1011, 'O+', 1, 13, 103),
    (1012, 'O-', 1, 14, 102),
    (1013, 'B-', 1, 14, 102),
    (1014, 'AB+', 0, 15, 101)
 ---------------------------------------------------------------
    CREATE TABLE DiseaseFinder (
        dfind_ID int NOT NULL PRIMARY KEY,
        dfind_name varchar(100) NOT NULL,
        dfind_PhNo bigint
    );

INSERT into
    DiseaseFinder
VALUES
(11, 'Peter', 9693959681),
    (12, 'Park', 9693959682),
    (13, 'Jerry', 9693959683),
    (14, 'shivam', 9693959672),
    (15, 'Monika', 9693959679);

INSERT into
    DiseaseFinder
VALUES
(16, 'Ram', 9693959684),
    (17, 'Swathi', 9693959685),
    (18, 'Gautham', 9693959686),
    (19, 'Ashwin', 9693959687),
    (20, 'Yash', 9693959688);