import java.util.ArrayList;

public class Broker {
   public Broker() {
      topics = new ArrayList<>();
   }
   public Topic createTopic (String topicName){
      Topic topic;
      if ((topic=findTopic(topicName))==null) {
         topic = new Topic(topicName);
         topics.add(topic);
      }
      return topic;
   }
   public boolean subscribe (Subscriber sub){
      Topic topic;
      String topicName = sub.getTopicName();
      if ((topic=findTopic(topicName))!=null) {
         topic.subscribe(sub);
         return true;
      } else 
         return false; // topic does not exist.
   }
   private Topic findTopic (String topicName) {
       for (Topic topic : topics) {
           if (topic.hasThisName(topicName)) {
               return topic;
           }
       }
      return null;
   }
   private ArrayList<Topic> topics;
}