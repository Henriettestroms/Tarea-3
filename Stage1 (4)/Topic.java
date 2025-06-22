import java.util.ArrayList;

public class Topic {
   protected Topic(){ // to ban calls to this constructor 

   }
   public Topic(String topicName) {
      this.topicName = topicName;
      subscribers = new ArrayList<>();
   }
   public void subscribe(Subscriber sub){
      subscribers.add(sub);
   }
   public void notify(String message) {
       for (Subscriber subscriber : subscribers) subscriber.update(message);
   }
   public boolean hasThisName(String name) {
      return topicName.equals(name);
   }
   private String topicName;
   private ArrayList<Subscriber> subscribers;
} 