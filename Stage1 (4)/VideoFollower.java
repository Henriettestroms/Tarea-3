import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;

public class VideoFollower extends Subscriber {
   public VideoFollower(String name, String topicName) {
      super(name, topicName);
      //??
   }
   public void update(String message) {
      //??
   }
   public HBox getView() {return view;}
   private HBox view;
   private Button video;
}