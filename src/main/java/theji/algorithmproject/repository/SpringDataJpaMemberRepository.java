package theji.algorithmproject.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import theji.algorithmproject.Member.Member;

import java.util.Optional;

public interface SpringDataJpaMemberRepository extends JpaRepository<Member,Long>, MemberRepository {
    @Override
    Optional<Member> findByName(String name);
}
