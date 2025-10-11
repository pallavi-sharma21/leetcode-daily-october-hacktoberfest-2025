class products:
    discount = 0
    count = 0 
    producting = []
    def __init__(self,name,price):
        self.name = name 
        self.price = price 
        products.count += 1
        self.product_id = f"PRD{products.count:03d}"
        products.producting.append(self)

    def bill(self):
        print(f"✅ {self.name} added with ID: {self.product_id}")
    
    def display_discount_price(self):
        discount  = self.price - (self.price*products.discount /100)
        print(f"{self.product_id} - {self.name} - rs{self.price} - rs{discount}")
    
    @classmethod
    def disc(cls,new_discount):
        cls.discount = new_discount 
        print(f"Discount changed to: {cls.discount}%")
    
    @classmethod
    def show_inventory(cls):
        print("\n ----Product Inventory----")
        for product in cls.producting:
            product.display_discount_price()

prod1 = products("phone",50000)
prod1.bill()
prod2 = products("Laptop",75000)
prod2.bill()
products.disc(10)
products.show_inventory()