using System;
using System.Diagnostics.Metrics;
using System.Drawing;
using System.Runtime.InteropServices.JavaScript;

namespace MyApp
{ 
    internal class Program
    {
        static void Main(string[] args)
        {
           
        }

    }
    // Задание 1
    /*
    class Employee
        {
            public string Name { get; set; }
        }

    class Journal
    {
        public string Name { get;set;}
        public List<Employee> NameEmployee = new List<Employee>();
        public int EmployeeCounter = 0;

            Journal(string name)
            {
                Name = name;
            }
            Journal(string name, Employee employee)
            {
                Name = name;
                NameEmployee.Add(employee);
                EmployeeCounter++;
            }
            public int getEmployeeCounter() => EmployeeCounter;

            public void addEmployee(Employee employee)
            {
                NameEmployee.Add(employee);
                EmployeeCounter++;
            }
            public void removeEmployee(Employee employee)
            {
                NameEmployee.Remove(employee);
                EmployeeCounter--;
            }

            public static Journal operator +(Journal journal, int data)
            {
                journal.EmployeeCounter += data;
                return journal;
            }
            public static Journal operator -(Journal journal, int data)
            {
                journal.EmployeeCounter -= data;
                return journal;
            }
            public static bool operator ==(Journal journal1, Journal journal2)
            {
                return journal1.EmployeeCounter == journal2.EmployeeCounter;
            }

            public static bool operator !=(Journal journal1, Journal journal2)
            {
                return journal1.EmployeeCounter != journal2.EmployeeCounter;
            }
            public static bool operator >(Journal journal1, Journal journal2)
            {
                return journal1.EmployeeCounter > journal2.EmployeeCounter;
            }

            public static bool operator <(Journal journal1, Journal journal2)
            {
                return journal1.EmployeeCounter < journal2.EmployeeCounter;
            }
            public override bool Equals(object obj)
            {
                if (obj == null || !(obj is Journal))
                {
                    return false;
                }

                Journal otherJournal = (Journal)obj;
                return this.EmployeeCounter == otherJournal.EmployeeCounter;
            }

            public override int GetHashCode()
            {
                return EmployeeCounter.GetHashCode();
            }





        }
    */

    //Задание 2
    /*
    class MobilePhone
    {
        public string Vendor { get; set; }
        public int price { get; set; }
        public MobilePhone(string name) => Vendor = name;
    }
    enum Vendors { Samsung, Apple, Nokia }

    class Shop
    {
        MobilePhone[] mobilePhones;
        public Shop(int count) => mobilePhones = new MobilePhone[count];
        public int Size => mobilePhones.Length;
        public float Sqare = 0;

        public MobilePhone this[int index]
        {
            get
            {
                if (index >= 0 && index < mobilePhones.Length)
                    return mobilePhones[index];
                throw new IndexOutOfRangeException();//выход за границы массива
            }
            set
            {
                mobilePhones[index] = value;
            }
        }
        public MobilePhone this[string name]
        {
            get
            {
                if (Enum.IsDefined(typeof(Vendors), name))
                    return mobilePhones[(int)Enum.Parse(typeof(Vendors), name)];
                else
                    throw new IndexOutOfRangeException();
            }
            set
            {

            }
        }
        public static Shop operator +(Shop shop, float sqare)
        {
            shop.Sqare += sqare;
            return shop;
        }
        public static Shop operator -(Shop shop, float sqare)
        {
            shop.Sqare -= sqare;
            return shop;
        }
        public static bool operator == (Shop shop1, Shop shop2)
        {
            return shop1.Sqare == shop2.Sqare;
        }

        public static bool operator !=(Shop shop1, Shop shop2)
        {
            return shop1.Sqare != shop2.Sqare;
        }
        public static bool operator >(Shop shop1, Shop shop2)
        {
            return shop1.Sqare > shop2.Sqare;
        }

        public static bool operator <(Shop shop1, Shop shop2)
        {
            return shop1.Sqare < shop2.Sqare;
        }
        public override bool Equals(object obj)
        {
            if (obj == null || !(obj is Shop))
            {
                return false;
            }

            Shop otherShop = (Shop)obj;
            return this.Sqare == otherShop.Sqare;
        }

        public override int GetHashCode()
        {
            return Sqare.GetHashCode();
        }
    }
    */

    // Задание 3

    class Book
    {
        public string Title { get; set; }
        public string Author { get; set; }

        public Book(string title, string author)
        {
            Title = title;
            Author = author;
        }

        public override string ToString()
        {
            return $"{Title} by {Author}";
        }
    }

    class ReadingList
    {
        private List<Book> books;

        public ReadingList()
        {
            books = new List<Book>();
        }

        public void AddBook(Book book)
        {
            books.Add(book);
        }

        public void RemoveBook(Book book)
        {
            books.Remove(book);
        }

        public bool ContainsBook(Book book)
        {
            return books.Contains(book);
        }

        public Book this[int index]
        {
            get { return books[index]; }
            set { books[index] = value; }
        }

        public static ReadingList operator +(ReadingList list, Book book)
        {
            list.AddBook(book);
            return list;
        }

        public static ReadingList operator -(ReadingList list, Book book)
        {
            list.RemoveBook(book);
            return list;
        }
    }


}

