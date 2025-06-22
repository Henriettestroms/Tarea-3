import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;

public class VideoPublisher extends Publisher {
    public VideoPublisher(String name, Broker broker, String topicName) {
        super(name, broker, topicName);
        //??
    }
    public HBox getView(){return view;}
    private HBox view;
    private TextField message;
}