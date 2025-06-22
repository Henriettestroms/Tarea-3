public class Publisher extends Component {
    protected Publisher() {} // to ban calls to this constructor
    public Publisher(String name, Broker broker, String topicName) {
        super(name, topicName);
        topic = broker.createTopic(topicName);
    }
    protected void publishNewEvent(String message) {
        topic.notify(message);
    }
    private Topic topic;
}