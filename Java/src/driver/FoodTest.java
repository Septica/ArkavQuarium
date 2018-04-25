/*import org.jboss.arquillian.container.test.api.Deployment;
import org.jboss.arquillian.junit.Arquillian;
import org.jboss.shrinkwrap.api.ShrinkWrap;
import org.jboss.shrinkwrap.api.asset.EmptyAsset;
import org.jboss.shrinkwrap.api.spec.JavaArchive;*/
import org.junit.Test;
//import org.junit.runner.RunWith;

import static org.junit.Assert.*;

//@RunWith(Arquillian.class)
public class FoodTest {
    private Aquarium aqtest1 = new Aquarium(50,50,100,10);
    private Aquarium aqtest2 = new Aquarium(60, 60, 100, 10);

    private Food food = new Food(aqtest1,2.5);
    private Vector2 pos = new Vector2(100,100);

    @Test
    public void isMove() throws Exception {
        food.setPosition(pos);
        Vector2 a = food.getPosition();

        food.move();

        Vector2 b = food.getPosition();
        assertNotEquals("Food is not moving", b, a);
    }

    @Test
    public void isTick() throws Exception {

    }

    @Test
    public void isDestruct() throws Exception {
        aqtest1.add(food);

        food.destruct();
        assertEquals(-1, aqtest1.getFoods().find(food));
    }

    /*@Deployment
    public static JavaArchive createDeployment() {
        return ShrinkWrap.create(JavaArchive.class)
                .addClass(Food.class)
                .addAsManifestResource(EmptyAsset.INSTANCE, "beans.xml");
    }*/

}
