create database dormitory_system;
use dormitory_system;
-- 宿管表
create table housemaster(
    h_account CHAR(10) NOT NULL,
    h_password CHAR(20) NOT NULL,
    PRIMARY KEY (h_account)
); 
-- 寝室长表
create table dormitory_Manager(
    d_account CHAR(10) NOT NULL,
    d_password CHAR(20) NOT NULL,
    PRIMARY KEY (d_account)
); 
-- 学生表
create table student(
    studentID CHAR(20) NOT NULL,#学号
    name CHAR(10) NOT NULL,#姓名
    sex char(5) NOT NULL,#性别
    major CHAR(30) NOT NULL,#专业
    class CHAR(20) NOT NULL,#班级
    dormitoryNumber CHAR(10) NOT NULL,#宿舍号
    dormBuilding CHAR(10) NOT NULL,#寝室楼
    phone CHAR(20),#电话
    PRIMARY KEY (StudentID)
);
drop table student;
-- 报修表
CREATE TABLE repair_report( 
    repairNumber INT NOT NULL AUTO_INCREMENT, 
    dormBuilding CHAR(10) NOT NULL, 
    dormitoryNumber CHAR(10) NOT NULL, -- 宿舍号 
    repair_time DATE, -- 时间 
    question CHAR(100) NOT NULL, -- 问题 
    situation CHAR(10) DEFAULT '等待处理', -- 状况 
    PRIMARY KEY (repairNumber)
);

-- 

CREATE TABLE dormitory (
    dormitoryNumber CHAR(10) NOT NULL, -- 宿舍号
    max_capacity INT NOT NULL, -- 最大容量
    dormBuilding CHAR(10) NOT NULL, -- 寝室楼
    PRIMARY KEY (dormitoryNumber)
);


-- 宿管表插入数据
INSERT INTO housemaster (h_account, h_password) VALUES ('account1', 'password1');
INSERT INTO housemaster (h_account, h_password) VALUES ('account2', 'password2');
INSERT INTO housemaster (h_account, h_password) VALUES ('account3', 'password3');
INSERT INTO housemaster (h_account, h_password) VALUES ('account4', 'password4');
INSERT INTO housemaster (h_account, h_password) VALUES ('account5', 'password5');

-- 插入学生表数据
INSERT INTO housemaster (h_account, h_password) VALUES 
('2022901439', '123456'),
('2022900968', '123456'),
('2022900969', '123456'),
('2022901078', '123456'),
('2022901080', '123456'),
('2022901146', '123456'),
('2022901184', '123456'),
('2022901290', '123456'),
('2022901531', '123456'),
('2022901540', '123456'),
('2022901543', '123456'),
('2022901544', '123456'),
('2022901607', '123456'),
('2022901776', '123456'),
('2022902065', '123456'),
('2022902069', '123456'),
('2022902201', '123456'),
('2022902208', '123456'),
('2022902641', '123456'),
('2022903322', '123456');

-- 宿管表表插入数据
INSERT INTO dormitory_Manager (d_account, d_password) VALUES ('Test', '123456');
INSERT INTO dormitory_Manager (d_account, d_password) VALUES ('manager2', 'pass2');
INSERT INTO dormitory_Manager (d_account, d_password) VALUES ('manager3', 'pass3');
INSERT INTO dormitory_Manager (d_account, d_password) VALUES ('manager4', 'pass4');
INSERT INTO dormitory_Manager (d_account, d_password) VALUES ('manager5', 'pass5');

-- 学生表插入数据
INSERT INTO student (studentID, name, sex, major, class, dormitoryNumber, dormBuilding, phone) VALUES 
('2022901439', '张伟', '男', '计算机科学与技术', 				'2022240201', '440', '15号楼', '13655695562'),
('2022900968', '王磊', '男', '物联网',						'2022240209', '440', '15号楼', '19855623214'),
('2022900969', '李强', '男', '计算机科学与技术(卓越工程师)', 		'2022240203', '440', '15号楼', '18715280656'),
('2022901078', '刘勇', '男', '软件工程', 					'2022240205', '440', '15号楼', '15206195865'),
('2022901080', '陈军', '男', '电子信息', 					'2022240302', '205', '12号楼', '13565638298'),
('2022901146', '杨洋', '男', '计算机科学与技术', 				'2022240202', '205', '12号楼', '18894560275'),
('2022901184', '赵刚', '男', '通信工程', 					'2022240306', '205', '12号楼', '19325490658'),
('2022901290', '黄进', '男', '软件工程', 					'2022240204', '205', '12号楼', '13598505455'),
('2022901531', '周宏', '男', '电子信息', 					'2022240303', '121', '15号楼', '17671694524'),
('2022901540', '吴平', '男', '计算机科学与技术(卓越工程师)', 		'2022240203', '121', '15号楼', '18918305690'),
('2022901543', '李娜', '女', '计算机科学与技术', 				'2022240202', '324', '14号楼', '18729263348'),
('2022901544', '刘洋', '女', '软件工程', 					'2022240205', '324', '14号楼', '19234695274'),
('2022901607', '陈静', '女', '计算机科学与技术', 				'2022240201', '324', '14号楼', '18153696724'),
('2022901776', '张敏', '女', '物联网', 						'2022240209', '324', '14号楼', '17854820436'),
('2022902065', '杨丽', '女', '物联网', 						'2022240209', '510', '11号楼', '15359571987'),
('2022902069', '赵丽影', '女', '软件工程', 					'2022240204', '510', '11号楼', '17346668612'),
('2022902201', '黄蓉', '女', '计算机科学与技术', 				'2022240201', '510', '11号楼', '17383046025'),
('2022902208', '周慧', '女', '通信工程', 					'2022240305', '510', '11号楼', '15697812484'),
('2022902641', '吴雪', '女', '物联网', 						'2022240209', '111', '14号楼', '15659030957'),
('2022903322', '徐婷', '女', '计算机科学与技术', 				'2022240202', '111', '14号楼', '13800565956');
delete from student;

-- 报修表插入数据
INSERT INTO repair_report (repairNumber,dormBuilding, dormitoryNumber, repair_time, question, situation) VALUES 
(1,'15号楼', '440', '2024-06-18', '水龙头漏水', '等待处理'),
(2,'11号楼', '510', '2024-06-19', '空调不制冷', '等待处理'),
(3,'14号楼', '111', '2024-06-27', '窗户破损', '等待处理');

delete from repair_report ;

delimiter $ 
create procedure my() begin       
alter table repair_report drop repairNumber; 
alter table repair_report add repairNumber int not null auto_increment primary key first; 
end $ delimiter ; 
设置定时事件 
show variables like '%event_sche%';-- 查看事件计划是否开启 
set global event_scheduler=1; 
create event on1  on schedule every 1 second do call my();-- 创建定时事务

-- 1、-- 创建触发器，在插入学生信息时自动填充账号和密码
DELIMITER //
CREATE TRIGGER fill_student_account_and_password BEFORE INSERT ON student
FOR EACH ROW
BEGIN
    INSERT INTO housemaster (h_account, h_password)
    VALUES (NEW.studentID, '123456');
END;
//
DELIMITER ;



-- 2-- 创建触发器，在插入学生信息时检查宿舍人数是否超过四人
DELIMITER //
CREATE TRIGGER check_dorm_capacity
BEFORE INSERT ON student
FOR EACH ROW
BEGIN
    DECLARE dorm_capacity INT;
    DECLARE current_dorm_count INT;

    -- 获取宿舍的最大容量
    SELECT max_capacity INTO dorm_capacity
    FROM dormitory;

    -- 获取当前宿舍的人数
    SELECT COUNT(*) INTO current_dorm_count
    FROM student
    WHERE dormitoryNumber = NEW.dormitoryNumber;

    -- 检查人数是否超过容量
    IF current_dorm_count >= dorm_capacity THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = '宿舍人数已满，请选择其他宿舍。';
    END IF;
END;
//
DELIMITER ;


3、-- 创建触发器，在插入学生信息时检查宿舍楼里的性别是否相同
DELIMITER //
CREATE TRIGGER check_dorm_gender
BEFORE INSERT ON student
FOR EACH ROW
BEGIN
    DECLARE dorm_gender CHAR(5);
    -- 获取当前宿舍楼的性别
    SELECT sex INTO dorm_gender
    FROM student
    WHERE dormitoryNumber = NEW.dormitoryNumber
        AND dormBuilding = NEW.dormBuilding
    LIMIT 1;

    IF dorm_gender IS NOT NULL AND dorm_gender <> NEW.sex THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = '宿舍楼里已有不同性别的学生，无法添加。';
    END IF;
END;
//
DELIMITER ;

4、-- 创建触发器，在修改学生信息时检查宿舍人数是否超过四人
DELIMITER //
CREATE TRIGGER check_dorm_capacity
BEFORE UPDATE ON student
FOR EACH ROW
BEGIN
    DECLARE dorm_capacity INT;
    -- 获取当前宿舍的人数
    SELECT COUNT(*) INTO dorm_capacity
    FROM student
    WHERE dormitoryNumber = NEW.dormitoryNumber
        AND dormBuilding = NEW.dormBuilding;

    IF dorm_capacity >= 4 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = '宿舍已满，无法修改更多学生信息。';
    END IF;
END;
//
DELIMITER ;




