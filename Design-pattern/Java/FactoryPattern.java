abstract class Plan {
    double price = 3.4;
    abstract double getPrice();
}

class DomesticPlan extends Plan {
    @Override
    double getPrice() {
        return 2.5;
    }
}

class InternationalPlan extends Plan {

    @Override
    double getPrice() {
        return 5.6;
    }
}

class CommercialPlan extends Plan {
    @Override
    double getPrice() {
        return 7.5;
    }
}

public class FactoryPattern {
    Plan getPlan(String type) {
        if (type == null) {
            return null;
        }
        if (type.equalsIgnoreCase("DomesticPlan")) {
            return  new DomesticPlan();
        }
        if (type.equalsIgnoreCase("InternationalPlan")) {
            return  new InternationalPlan();
        }
        if (type.equalsIgnoreCase("CommercialPlan")) {
            return new CommercialPlan();
        }
        return  null;
    }

    public static void main(String[] args) {
        FactoryPattern pattern = new FactoryPattern();
        Plan plan = pattern.getPlan("InternationalPlan");
        System.out.println(plan.getPrice());
    }
}
