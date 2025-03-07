# Dictionary to store contacts in memory (will be lost after exiting)
contacts = {}

# Function to add a contact
def add_contact():
    name = input("Enter name: ").strip()
    phone = input("Enter phone number: ").strip()
    email = input("Enter email: ").strip()
    address = input("Enter address: ").strip()

    if name in contacts:
        print("❌ Contact already exists!")
        return

    contacts[name] = {"Phone": phone, "Email": email, "Address": address}
    print(f"✅ Contact '{name}' added successfully!")

# Function to view contacts
def view_contacts():
    if not contacts:
        print("📂 No contacts available.")
        return
    
    print("\n📖 Contact List:")
    for name, details in contacts.items():
        print(f"📌 {name} | 📞 {details['Phone']} | ✉️ {details['Email']} | 🏠 {details['Address']}")

# Function to search for a contact
def search_contact():
    query = input("Enter name or phone number to search: ").strip()
    
    found = False
    for name, details in contacts.items():
        if query.lower() in name.lower() or query in details["Phone"]:
            print(f"🔍 Found: {name} | 📞 {details['Phone']} | ✉️ {details['Email']} | 🏠 {details['Address']}")
            found = True

    if not found:
        print("❌ No matching contacts found.")

# Function to update a contact
def update_contact():
    name = input("Enter the name of the contact to update: ").strip()

    if name not in contacts:
        print("❌ Contact not found!")
        return

    print(f"Editing contact: {name}")
    phone = input(f"Enter new phone number (Current: {contacts[name]['Phone']}): ").strip() or contacts[name]["Phone"]
    email = input(f"Enter new email (Current: {contacts[name]['Email']}): ").strip() or contacts[name]["Email"]
    address = input(f"Enter new address (Current: {contacts[name]['Address']}): ").strip() or contacts[name]["Address"]

    contacts[name] = {"Phone": phone, "Email": email, "Address": address}
    print(f"✅ Contact '{name}' updated successfully!")

# Function to delete a contact
def delete_contact():
    name = input("Enter the name of the contact to delete: ").strip()

    if name in contacts:
        del contacts[name]
        print(f"🗑️ Contact '{name}' deleted successfully!")
    else:
        print("❌ Contact not found!")

# Main function
def main():
    while True:
        print("\n📞 Contact Book")
        print("1️⃣ Add Contact")
        print("2️⃣ View All Contacts")
        print("3️⃣ Search Contact")
        print("4️⃣ Update Contact")
        print("5️⃣ Delete Contact")
        print("6️⃣ Exit")

        choice = input("Enter your choice (1-6): ").strip()

        if choice == "1":
            add_contact()
        elif choice == "2":
            view_contacts()
        elif choice == "3":
            search_contact()
        elif choice == "4":
            update_contact()
        elif choice == "5":
            delete_contact()
        elif choice == "6":
            print("👋 Exiting Contact Book. Have a great day!")
            break
        else:
            print("❌ Invalid choice! Please enter a number between 1-6.")

# Run the Contact Book
if __name__ == "__main__":
    main()
# Output:
# 📞 Contact Book
# 1️⃣ Add Contact
# 2️⃣ View All Contacts
# 3️⃣ Search Contact
# 4️⃣ Update Contact
# 5️⃣ Delete Contact
# 6️⃣ Exit
# Enter your choice (1-6): 1
# Enter name: Swarnava
# Enter phone number: 1234567989
# Enter email: jaga@gmail.com
# Enter address: jagaddal
# ✅ Contact 'Swarnava' added successfully!
# 📞 Contact Book
# 1️⃣ Add Contact
# 2️⃣ View All Contacts
# 3️⃣ Search Contact
# 4️⃣ Update Contact
# 5️⃣ Delete Contact
# 6️⃣ Exit
# Enter your choice (1-6): 1
# Enter name: Suti
# Enter phone number: 0987654321
# Enter email: suti@gmail.com
# Enter address: Midnapore
# ✅ Contact 'Suti' added successfully!
# 📞 Contact Book
# 1️⃣ Add Contact
# 2️⃣ View All Contacts
# 3️⃣ Search Contact
# 4️⃣ Update Contact
# 5️⃣ Delete Contact
# 6️⃣ Exit
# Enter your choice (1-6): 2
# 📖 Contact List:
# 📌 Swarnava | 📞 1234567989 | ✉️ jaga@gmail.com | 🏠 jagaddal
# 📌 Suti | 📞 0987654321 | ✉️ suti@gmail.com | 🏠 Midnapore
# 📞 Contact Book
# 1️⃣ Add Contact
# 2️⃣ View All Contacts
# 3️⃣ Search Contact
# 4️⃣ Update Contact
# 5️⃣ Delete Contact
# 6️⃣ Exit
# Enter your choice (1-6): 3
# Enter name or phone number to search: Suti
# 🔍 Found: Suti | 📞 0987654321 | ✉️ suti@gmail.com | 🏠 Midnapore
# 📞 Contact Book
# 1️⃣ Add Contact
# 2️⃣ View All Contacts
# 3️⃣ Search Contact
# 4️⃣ Update Contact
# 5️⃣ Delete Contact
# 6️⃣ Exit
# Enter your choice (1-6): 4
# Enter the name of the contact to update: Suti
# Editing contact: Suti
# Enter new phone number (Current: 0987654321): 2345678901
# Enter new email (Current: suti@gmail.com): sutrishna@gmail.com
# Enter new address (Current: Midnapore): Kolkata
# ✅ Contact 'Suti' updated successfully!
# 📞 Contact Book
# 1️⃣ Add Contact
# 2️⃣ View All Contacts
# 3️⃣ Search Contact
# 4️⃣ Update Contact
# 5️⃣ Delete Contact
# 6️⃣ Exit
# Enter your choice (1-6): 5
# Enter the name of the contact to delete: Suti
# 🗑️ Contact 'Suti' deleted successfully!
# 📞 Contact Book
# 1️⃣ Add Contact
# 2️⃣ View All Contacts
# 3️⃣ Search Contact
# 4️⃣ Update Contact
# 5️⃣ Delete Contact
# 6️⃣ Exit
# Enter your choice (1-6): 6
# 👋 Exiting Contact Book. Have a great day!
