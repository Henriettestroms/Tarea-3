public class Component {
   protected Component (){}  // to ban creation of publisher or subscriber without name.
   public Component(String componentName, String topicName){
      name=componentName;
      this.topicName = topicName;
   }
   public String getName(){
      return name;
   }
   public String getTopicName(){
      return topicName;
   }
   protected String name;
   protected String topicName;
}