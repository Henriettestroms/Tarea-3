public abstract class Subscriber extends Component {
   protected Subscriber() {}  // to ban calls to this constructor.
   public Subscriber(String name, String topicName) {
      super(name, topicName);
   }
   public abstract void update(String message);
}